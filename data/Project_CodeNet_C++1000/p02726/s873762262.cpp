#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main() {
    int n,x,y;
    cin >> n >> x >> y;
    
    int a[n-1];
    for(int i=0;i<n-1;i++) a[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) a[min(j-i,min(abs(x-i)+1+abs(y-j),abs(y-i)+1+abs(x-j)))-1]++;
    }

    for(int i=0;i<n-1;i++) cout << a[i] << endl;
}