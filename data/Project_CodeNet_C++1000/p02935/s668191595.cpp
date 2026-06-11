#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    sort(v.begin(),v.end(),greater<int>());
    
    stack<double> quarity;
    for(int i=0;i<n;i++){
        quarity.push(v[i]);
    }
    
    for(int i=0;i<n-1;i++){
        double x,y;
        x = quarity.top();    quarity.pop();
        y = quarity.top();    quarity.pop();
        quarity.push((x+y)/2);
    }
    
    cout << quarity.top() << endl;
    quarity.pop();
    
    return 0;
}
