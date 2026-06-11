#include<iostream>
using namespace std;

long long MOD = 1000000007;

long long extGCD(long long a, long long b, long long *px, long long *py){
    if(b == 0){
        *px = 1;
        *py = 0;
        return a;
    }
    long long d = extGCD(b, a%b, py, px);
    *py -= a/b * (*px);
    return d;
}

int main(){
    //input
    long long N, M;
    cin >> N >> M;
    long long a[N+1], a_nibeki[N+1];
    long long i;
    for(i=1; i<=N; i++){
        cin >> a[i];
        a_nibeki[i] = a[i];
    }

    //calc
    bool nibeki_safe=1;
    bool over_safe = 1;
    long long nibeki_first=0;
    long long nibeki_other;
    long long x,y;
    long long lcm_ya;
    long long ans=0;
    while(a_nibeki[1]%2==0){
        nibeki_first++;
        a_nibeki[1] = a_nibeki[1]/2;
    }
    for(i=2; i<=N; i++){
        nibeki_other=0;
        while(a_nibeki[i]%2==0){
            nibeki_other++;
            a_nibeki[i] = a_nibeki[i]/2;
        }
        if(nibeki_other!=nibeki_first){
            nibeki_safe = 0;
        }
    }
    lcm_ya=a[1];
    for(i=2; i<=N; i++){
        lcm_ya = lcm_ya*a[i]/extGCD(lcm_ya,a[i],&x,&y);
        if(lcm_ya>2*M){
            over_safe = 0;
            break;
        }
    }
    if(lcm_ya<=2*(M%lcm_ya)){
        ans++;
    }
    ans += M/lcm_ya;

    //answer
    if(nibeki_safe && over_safe){
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    system("pause");
    return 0;

}