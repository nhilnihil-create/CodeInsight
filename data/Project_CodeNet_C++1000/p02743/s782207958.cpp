
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 04 September 2020 11:18:23 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define lgt(s) ((int)s.length())
#define int long long
#define ld long double
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
            ld a,b,c;
            cin>>a>>b>>c;
            ld y = (ld)sqrt((ld)b);
            ld x = (ld)sqrt((ld)a);
            ld z = (ld)sqrt((ld)c);
            ld eps = 1.0E-14;
            if( (ld)x + (ld)y + eps < (ld)z ){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

