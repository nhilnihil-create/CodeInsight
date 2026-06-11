#include <bits/stdc++.h>
using namespace std;
 

 
int main() {


    int64_t n;
    cin>>n;

    vector<int64_t> L(n);
    for(int i=0;i<n;i++){
        cin>>L.at(i);
    }


    sort(L.begin(), L.end(), greater<int64_t>());

    // a < b + c
    int cnt=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(L.at(i)<L.at(j)+L.at(k))
                    cnt++;
            }
        }
    }

    cout<<cnt<<endl;

 	return 0;
}
