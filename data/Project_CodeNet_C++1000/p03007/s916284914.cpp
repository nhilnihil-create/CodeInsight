#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> A(N,0);

    int ans = 0;

    priority_queue<int> queP;
    priority_queue<int> queN;
    for(int i=0; i<N; i++){
        cin >> A[i];
        ans+=abs(A[i]);
        if(A[i]>=0){
            queP.push(-A[i]);
        }else{
            queN.push(A[i]);
        }
    }

    if((int) queP.size() !=0 && (int) queN.size()!=0){
        cout << ans << endl;
        int tmp = queP.top();
        queP.pop();
        queP.push(-queN.top());
        queN.pop();
        queN.push(-tmp);
    }else if((int) queP.size()!=0){
        cout << ans + 2*queP.top() << endl;
    }else{
        cout << ans + 2*queN.top() << endl;
    }

    while((int) queP.size() >1){
        int x = -queP.top();
        queP.pop();
        int y = -queP.top();
        queP.pop();
        if((int) queP.size()==0 && (int) queN.size() == 0){
            cout << y << ' ' << x << endl;
            return 0;
        }else{
            cout << x << ' ' << y << endl;
        }
        queP.push(-x+y);
    }

    if((int) queP.size() == 1){
        queN.push(-queP.top());
    }
    while((int) queN.size() >1){
        int x = queN.top();
        queN.pop();
        int y = queN.top();
        queN.pop();
        cout << x << ' ' << y << endl;
        queN.push(x-y);
    }

}