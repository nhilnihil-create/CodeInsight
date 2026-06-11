#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353a
#define pi acos(-1)
#define all(v) v.begin(),v.end()
 
int main(){
    int N;
    string s;
    cin>>N;
    cin>>s;
    int count=0;
    for(int i=0;i<s.size()-2;i++){
        if (s.at(i)=='A'){
            if (s.at(i+1)=='B'){
                if (s.at(i+2)=='C'){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}