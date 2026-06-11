
/*
	*	Created By: 'Present_Sir'
	*	Created On: Thursday 27 August 2020 02:26:52 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define lgt(s) ((int)s.length())
#define int long long
using namespace std;

class Solver{
    public:
        void test(){
            //int t; cin>>t; for(int i=1; i<=t; ++i)
            {
                //cout<<"Case #"<<i<<": ";
                this->solve();
            }
        }
        void solve(){
            int ar[5];
            for(int i=0; i<5; ++i){
                cin>>ar[i];
                if(ar[i] == 0){
                    cout<<i+1<<endl;
                    return;
                }
            }
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

