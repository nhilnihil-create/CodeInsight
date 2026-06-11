#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <functional>
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin >> n;

    int m_cnt = 0;
    vector<int> a(n);

    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] < 0){
            m_cnt++;
            sum -= a[i];
        }
        else sum += a[i];
    }

    if(m_cnt <= 1){
        sort(a.begin(),a.end());
        if(m_cnt == 0)sum -= 2 * a[0];
        cout << sum << endl;
        int now = a[0];

        for(int i = 1;i < n;i++){
            if(i != n - 1){
                cout << now << " " << a[i] << endl;
                now -= a[i];
            }else{
                cout << a[i] << " " <<  now << endl;
            }
        }
    }
    else if(m_cnt >= n-1){
        sort(a.begin(),a.end());
        if(m_cnt == n)sum += 2 * a[n-1];
        cout << sum << endl;
        int now = a[n-1];

        for(int i = 0;i < n -1;i++){
            cout << now << " " << a[i] << endl;
            now -= a[i];
        }
    }
    else{
       sort(a.begin(),a.end());
       cout << sum << endl;

       int m = a[0];
       int p = a[n-1];

       for(int i = 1;i < n-1;i++){
           if(a[i] < 0){
               cout << p << " " << a[i] << endl;
               p -= a[i];
           }
           else{
               cout << m << " " << a[i] << endl;
               m -= a[i];
           }
       }
       cout << p << " " << m << endl;
    }
}
