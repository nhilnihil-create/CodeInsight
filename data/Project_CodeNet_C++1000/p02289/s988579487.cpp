#include<queue>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string cmd;
    priority_queue<int> Q;
    while(cin>>cmd&&cmd!="end"){
        if(cmd=="insert"){
            int m;
            cin>>m;
            Q.push(m);
        }
        else if (cmd=="extract"){
            int n=Q.top();
            Q.pop();
            cout<<n<<endl;
        }
    }
    return 0;
}