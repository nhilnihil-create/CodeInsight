#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int k,n;
    vector<int>d;
    int num;
    cin >>k >> n;
    int dd =0 ;
    for(int i=0;i<n;i++){
        cin >> num;
        d.push_back(num);
        if(i){
            dd=max(dd,d[i]-d[i-1]);
        }
    }
    dd=max(dd,d[0]+k-d[n-1]);
    cout << k-dd << endl;
    return 0;
}
