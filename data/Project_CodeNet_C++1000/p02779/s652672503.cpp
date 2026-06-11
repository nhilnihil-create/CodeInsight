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
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    int n;
    cin >> n;
    vector<intl> a;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());

    int check=1;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            check=0;
            break;
        }
    }

    if(check){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
