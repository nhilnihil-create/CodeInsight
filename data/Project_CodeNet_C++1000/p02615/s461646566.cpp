#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec;
    long ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    if(n%2){
        ans += vec.front();
        for(int i=1;i<n/2;i++)
            ans += 2*vec[i];
        ans += vec[(n/2)];
    }
    else{
        ans += vec.front();
        for(int i=1;i<n/2;i++)
            ans += 2*vec[i];
    }
    cout<<ans<<endl;
}
