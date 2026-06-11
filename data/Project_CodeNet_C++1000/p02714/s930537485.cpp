#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
    if(x%y==0)return y;
    else return gcd(y,x%y);
}

int main(){
    /* A
    int n;
    cin >> n;
    bool check = false;
    for(int i=0;i<3;i++){
        if(n%10 == 7)check = true;
        n/=10;
    }
    cout << ((check)? "Yes": "No") << endl;*/

    /* B
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for(int i=1;i<=n;i++){
        if(i%3!=0&&i%5!=0)ans+=i;
    }
    cout << ans << endl;*/

    /* C
    int k;
    cin >> k;
    int ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                ans += gcd(gcd(i,j),l);
            }
        }
    }
    cout << ans << endl;*/

    int n;
    cin >> n;
    string s;
    cin >> s;
    string check="RGB";
    vector<long long> rgb(3,0);
    for(int i=0;i<n;i++)for(int j=0;j<3;j++)if(check.at(j)==s.at(i))rgb[j]++;

    //条件1の組み合わせ数はR*G*B
    long long ans=rgb[0]*rgb[1]*rgb[2];
    //条件2の組み合わせ数は　すべて（条件１）の組み合わせ数 -  (j-i!=k-jの条件以外　つまりk=2*j-iを引けばいい)
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int k = j + (j-i);
            if(k < n){
                if(s[i] != s[j] && s[i]!=s[k]&&s[j]!=s[k])ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}