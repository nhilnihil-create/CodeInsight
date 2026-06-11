#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;    
const int size = 1000000;
int arr[size+1] = {};
main(){
    
    arr[1] = 1;
    for(int i = 2;i * i <= size;i++){
        if(arr[i])continue;
        for(int j = i * 2;j <= size;j += i){
            arr[j] = 1;
        }
    }
    set<int> prime;
    rep(i,1,size+1)if(!arr[i])prime.insert(i);

    //rep(i,1,30)if(prime.count(i))cout << i << endl;

    int A,D,N;
    cin >> A >> D >> N;
    while(A){
        int cnt = 0,num = A - D;
        while(cnt < N){
            num += D;
            if(prime.count(num))cnt++;
        }
        cout << num << endl;
        cin >> A >> D >> N;
    }
}
