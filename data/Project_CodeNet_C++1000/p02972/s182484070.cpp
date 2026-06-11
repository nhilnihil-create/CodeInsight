#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> a(N+1);
    for(int i = 1; i <= N;i++){
        cin >> a[i];
    }
    
    vector<int> ans;
    vector<int> b(N+1,0);
    for(int i = N; i >= 1;i--){
        int sum = 0;
        for(int j = i;j <= N;j +=i){
            sum += b[j];
        }
        if((sum+a[i])%2 == 1){
            b[i]++;
            ans.push_back(i);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    cout<< ans.size()<<endl;
    for(auto x:ans)cout << x <<" ";
    
    
    
}
