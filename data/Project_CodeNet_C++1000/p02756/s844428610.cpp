#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    int t,f;
    char c;
    int flag=0;
    string head,rear;
    for(int i=0;i<q;i++){
        cin >> t;
        if(t==1){
            flag=(flag+1)%2;
        }else{
            cin >> f >> c;
            if(flag==0){
                if(f==1){
                    head+=c;
                }else{
                    rear+=c;
                }
            }else{
                if(f==1){
                    rear+=c;
                }else{
                    head+=c;
                }
            }
        }
    }
    reverse(head.begin(),head.end());
    string ans=head+s+rear;
    if(flag) reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}