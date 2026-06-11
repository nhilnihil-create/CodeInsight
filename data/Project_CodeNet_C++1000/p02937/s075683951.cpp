// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "test"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 50;
vector<int> pos[26];
int main(){
    //ifstream cin(NAME".inp");
    string s,t;
    cin>>s>>t;

    for(int i=0;i<s.len;i++) pos[s[i]-'a'].push_back(i);

    for(int i=0;i<t.len;i++) if (pos[ t[i]-'a' ].size()==0 ) {
        cout<<-1;
        return  0;
    }

    int pre = -1;
    int cycle = 0;
    int id;
    for(int i=0;i<t.len;i++){
        id = lower_bound( pos [t[i]-'a' ].begin(),pos [t[i]-'a' ].end() ,pre+1) - pos [t[i]-'a' ].begin();
        if (id == pos [t[i]-'a' ].size()){
            // do recycle
            pre = pos [t[i]-'a' ][0];
            cycle++;
        }else{
            pre = pos[t[i]-'a'][id];
        }
    }
    cout<<s.len*cycle + pre+1<<endl;
}
