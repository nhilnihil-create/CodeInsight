#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    queue<long long> que;
    if(k<=9){
        cout << k << endl;
        return 0;
    }
    for(int i=1;i<=9;i++){
        que.push(i);
    }
    long long tmp;
    for(int i=0;i<k;i++){
        tmp=que.front();
        if(tmp%10!=0) que.push(tmp*10+(tmp%10-1));
        que.push(tmp*10+(tmp%10));
        if(tmp%10!=9) que.push(tmp*10+(tmp%10+1));
        que.pop();
        //cout << tmp << endl;
    }
    cout << tmp << endl;
    return 0;
}