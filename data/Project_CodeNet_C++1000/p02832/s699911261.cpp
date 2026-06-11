#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
typedef long long ll;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    int j = 1;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(v[i] != j)   ans++;
        else    j++;
    }
    if(ans==N)  ans = -1;
    cout << ans;
}