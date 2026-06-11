#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	string S;
	cin>>S;
    ll K;
    cin>>K;
    ll ans = 0;
    ll s_ind = 0,f_ind = S.length();
    if(S.front()==S.back()){
        ll nf=0,nb=0;      
        while(S[nf]==S.front()){
            nf++;
            if(nf==S.length()){
                break;
            }
        }
        if(nf==S.length()){
            cout<<(S.length()*K)/2<<"\n";
            return 0;
        }else{
            while(S[S.length()-1-nb]==S.back()){
                nb++;
            }
        }
        ans += ((nf+nb)/2)*(K-1);        
        ans += nf/2 + nb/2;

        s_ind += nf;
        f_ind -= nb;
    }
    char c_old = S[s_ind];
    ll n = 1;
    rep(i,f_ind - s_ind-1){
        if(S[s_ind+i+1]==c_old){
            n++;
        }else{
            ans += n/2*K;
            n = 1;
            c_old = S[s_ind+i+1];
        }
    }
    ans += n/2*K;

    cout<<ans<<"\n";

	return 0;
}