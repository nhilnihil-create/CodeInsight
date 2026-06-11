#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<long long> PF(long long N){
    vector<long long> res;
    for(long long i=2;i*i<=N;i++){
        if(N%i==0){
            res.push_back(i);
            N/=i;
            i--;
        }
    }
    res.push_back(N);
    return res;
}

long long N;
long long ans;
void g(long long a,long long n){
    //cout<<a<<" "<<n<<endl;
    while(n%a==0){
        n/=a;
    }

    if(n%a==1){
        ans++;
    }
    return;
}

void f(map<long long,int>& m,long long a,long long b){
    if(m.upper_bound(b)==m.end()){
        for(int i=0;i<=m[b];i++){
            if(a!=1){
                g(a,N);
            }
            a*=b;
        }
        return;
    }else{
        for(int i=0;i<=m[b];i++){
            auto p=*m.upper_bound(b);
            f(m,a,p.first);
            a*=b;
        }
    }

}

int main(){
    cin>>N;
    if(N==2){
        cout<<1<<endl;
        return 0;
    }

    auto v_m=PF(N-1);
    auto v_n=PF(N);
    /*
    for(auto p:v_m){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto p:v_n){
        cout<<p<<" ";
    }
    cout<<endl;
    //*/

    long long pro=1;
    long long tmp=0;
    long long cnt=0;
    for(auto p:v_m){
        if(tmp==p){
            cnt++;
        }else{
            pro*=cnt+1;
            cnt=1;
        }
        tmp=p;
    }
    pro*=cnt+1;
    ans=pro-1;
    //cout<<ans<<endl;

    map<long long,int> m;
    for(auto p:v_n){
        m[p]++;
    }
    f(m,1,v_n[0]);
    cout<<ans<<endl;
    return 0;
}