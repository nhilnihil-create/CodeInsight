#include<bits/stdc++.h>
#define mp make_pair
#define endl "\n"
#define v vector
#define b begin()
#define e end()
using namespace std;
typedef long long ll;
typedef long l;
typedef long long unsigned ull;

int main(){

    float n,m;
    vector <int> arr;
    cin>>n>>m;
    int sum = 0,total = 0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
        sum += k;
    }
    float val = sum/(4*m);

    //cout<<sum<<" "<<val;

    for(int i=0;i<n;i++){
        if(arr[i]>=val){
            total++;
        }
    }
    if(total>=m){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


    return 0;

}
