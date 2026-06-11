#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000

int main(){
    while(true){
        int n;
        cin >> n;

        if(n==0)
            break;
        
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        
        sort(a.begin(), a.end());

        int d = INF;
        for(int i=1;i<n;i++)
            d = min(d, a[i]-a[i-1]);
        
        cout << d << endl;
    }
    return 0;
}
