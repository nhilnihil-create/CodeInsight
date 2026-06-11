#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,m;
    cin>>n>>m;

    vector<double> arr;
    double total=0;
    for(int i=0;i<n;i++) {
        double num;
        cin>>num;
        total+=num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int count=0;
    double limit=(1/(4*double(m)));
    for(int i=0;i<m;i++) {
        double percentage=(arr[i]/double(total));
        if(percentage>=limit) {
            count++;
        }
    }

    if(count==m) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }

}


