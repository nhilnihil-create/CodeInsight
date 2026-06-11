#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MX = 1e18;

int main(){
    int N;
    cin >> N;
    ll A[N];
    int zero = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i] == 0){
            zero++;
        }
    }

    if(zero>0){
        printf("0\n");
        return 0;
    }

    ll prod = 1;
    for(int i=0; i<N; i++){
        if(A[i] <= MX/prod){
            prod *= A[i];
        } else{
            printf("-1\n");
            return 0;
        }
    }

    cout << prod << endl;
    return 0;
}