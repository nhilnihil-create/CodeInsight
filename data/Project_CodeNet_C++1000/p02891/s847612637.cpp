#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#define N (998244353)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> Q;

int p[200010];



int main(void){
    ll k;
    string s;
    cin>>s>>k;
    vector<P>pi;
    for(int i=0;i<s.length();){
        int j=i;
        while(true){
            if(i==s.length())break;
            if(s[i]==s[j])i++;
            else{
                break;
            }
        }
        pi.push_back(P(s[j]-'a',i-j));
    }
    if(pi.size()==1){
        ll se = pi[0].second;
        if(pi[0].second%2==0){
            cout<<(pi[0].second/2)*k<<endl;
        }
        else{
            ll e = (se-1)/2;
            ll o = e+1;
            if(k%2==0)cout<<e*(k/2)+o*(k/2)<<endl;
            else cout<<((k-1)/2)*o+((k-1)/2+1)*e<<endl;
        }
    }
    else{
        if(pi[0].first!=pi[pi.size()-1].first){
            ll seq=0;
            for(int i=0;i<pi.size();i++){
                if(pi[i].second==1)continue;
                else seq+=(pi[i].second/2);
            }
            cout<<seq*k<<endl;
        }
        else{
            ll seq = 0;
            for(int i=1;i<pi.size()-1;i++){
                if(pi[i].second==1)continue;
                else seq+=(pi[i].second/2);
            }
            ll seq1=0;
            ll num1 = pi[0].second;
            ll num2 = pi[pi.size()-1].second;
            if((num1%2==1)&&(num2%2==1)){
                ll t = num1/2+num2/2+1;
                cout<<seq*k+t*(k-1)+num1/2+num2/2<<endl;
            }
            else{
                cout<<((num1+num2)/2)*k+seq*k<<endl;
            }
        }
    }
    return 0;
}