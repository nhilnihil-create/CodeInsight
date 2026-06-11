#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    cin >> n;
    double arr[n + 5];
    priority_queue<double, vector<double>, greater<double>> p;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        p.push(arr[i]);
    }
    while(p.size()){
        if(p.size() == 1)
            return cout << fixed << setprecision(5) << p.top(), 0;
        double a = p.top();
        p.pop();
        double b = p.top();
        p.pop();
        p.push((a + b)/2.0);
    }
    return 0;
}
