#include<bits/stdc++.h>
using namespace std;
int main(){
    long x;
    cin >> x;
    queue<long>q;
    q.push(0);
    bool chk=false;
    vector<bool>chkk(100001,false);
    while(!q.empty()){
        long tmp = q.front();
        q.pop();
        if(tmp == x){
            chk=true;
            break;
        }else if(tmp > x){
            continue;
        }else if(chkk[tmp]){
            continue;
        }else{
            chkk[tmp]=true;
        }
        for(int i=100;i<=105;i++){
            q.push(tmp+i);
        }
    }
    if(chk)cout<<1<<endl;
    else cout<<0<<endl;
}