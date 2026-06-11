#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    int muki=0;
    deque<char> ans;
    for(char c:s){
      ans.push_back(c);
    }
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            if(muki==0)muki++;
            else muki--;
        }
        else{
            int f;
            cin >> f;
            char c;
            cin >> c;
            if((f==1&&muki==0)||(f==2&&muki==1)){
                ans.push_front(c);
            }
            else{
                ans.push_back(c);
            }
        }
    }
  if(muki==0){
    while(!ans.empty()){
        cout << ans.front();
        ans.pop_front();
    }
    cout << endl;
  }
  else{
    while(!ans.empty()){
        cout << ans.back();
        ans.pop_back();
    }
    cout << endl;
  } 
}
