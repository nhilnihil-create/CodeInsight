#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter[n];
    for(int i=0;i<n;i++) counter[i] = 0;
    for(int i=0;i<n-1;i++){
        int a;
        cin >> a;
        counter[a-1]++;
    }
    for(int i=0;i<n;i++) cout << counter[i] << endl;
}