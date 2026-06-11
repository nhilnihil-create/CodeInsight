#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<
      double,                // 要素の型はint
      vector<double>,   // 内部コンテナはstd::vector (デフォルトのまま)
      greater<double>   // 昇順 (デフォルトはstd::less<T>)
    > que;
    double v;
    double ans=0;
    double num1,num2;

    for(int i=0; i<n; i++){
        cin >> v;
        que.push(v);
    }

    for(int i=0; i<n-1; i++){
        num1=que.top();
        que.pop();
        num2=que.top();
        que.pop();
        que.push((num1+num2)/2);
//        cout << num1 << ' ' << num2 << endl;
    }

    cout << que.top() << endl;
    que.pop();
}