#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    queue<string> title;
    queue<int> length;
    for(int i=0; i<n; i++){
        string t; int l; cin>>t>>l;
        title.push(t);
        length.push(l);
    }
    string x; cin >>x;
    int ans = 0;
    while(true && title.size()>0){
        if(title.front()==x){
            title.pop(); length.pop(); break;
        }
        else title.pop(); length.pop();
    }
    while(true && length.size()>0){
        ans+=length.front();
        length.pop();
    }
    cout << ans << endl;
}