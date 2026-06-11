#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int N,K,C;
int A[200001];
int B[200001];
vector<int> ans;
 
 
 
int main(){
    int k = 0;
    int cntt=0;
    cin >> N >> K >> C;
    int cnt=10000001;
    for(int i=0;i<N;i++){
        char s;
        cin >> s;
        if (s == 'o' && cnt < C){
            A[i] = 1;
            cnt++;
        } else if (s == 'x'){
            A[i] = 0;
            cnt++;
        } else {
            A[i] = 2;
            B[k] = cnt;
            cnt = 0;
            k++;
            cntt = i;
        }
    }
    B[k] = N-cntt-1;
    
    if (k>K){
        return 0;
    }
    int i=N-1;
    int cnttt = C;
    while(k>0){
        for (int j=0;j<B[k]+1;j++){
            if(A[i-j] == 1){
                if(C-j <= cnttt){
                    cnttt = B[k]-j;
                    break;
                }
            }else if(A[i-j] == 2){
                cnttt = 0;
                ans.push_back(i-j+1);
            }
        }
        i -= (B[k]+1);
        k--;
    }
    for(ll j=ans.size()-1;j>=0;j--){
        cout << ans[j] << endl;
    }
    
}