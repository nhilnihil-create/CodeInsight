#include <iostream>
#include <queue>
using namespace std;
int main(void){
    // Your code here!
    int a,tf;
    queue<int> h;
    for(int i=1;i<=28;i++){
        cin>>a;
        h.push(a);
    }
    for(int i=1;i<=30;i++){
        tf=0;
        for(int i2=1;i2<=28;i2++){
            if(h.empty())break;
            a=h.front();
            h.pop();
            if(i==a){
                tf=1;
                break;
            }
            else h.push(a);
        }
        if(tf==0)cout<<i<<endl;
    }
}