#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    string s;
    int q;
    cin >> s >> q;

    int rev=0;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            if(rev){
                rev = 0;
            }else{
                rev = 1;
            }
        }
        if(t==2){
            int f;
            char c;
            cin >> f >> c;
            if(f==1){
                if(rev){
                    s += c;
                }else{
                    s = c+s;
                }
                
            }
            if(f==2){
                if(rev){
                    s = c+s;
                }else{
                    s += c;
                }
            }
        }
    }
    if(rev) reverse(s.begin(),s.end());
    cout << s << endl;
}