#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    string s;
    cin>>s;
    int q, k=0;
    cin>>q;
    while(q--) {
        int t;
        cin>>t;
        if(t==1) {
            k^=1;
        }
        else if(t==2) {
            int f;
            string c;
            cin>>f>>c;
            if(f==1) {
                if(k==1) {
                    s+=c;
                } else {
                    c+=s;
                    s=c;
                }
            } else {
                if(k==0) {
                    s+=c;
                } else {
                    c+=s;
                    s=c;
                }
            }
        }
    }
    if(k)
        reverse(s.begin(), s.end());
    cout<<s;

}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
