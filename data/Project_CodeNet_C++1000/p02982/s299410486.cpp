#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d;
    cin>>n>>d;
    vector<vector<int>> data(n, vector<int>(d));
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>data.at(i).at(j);
        }
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            float len=0;
            for(int k=0;k<d;k++){
                
                len+=(data.at(i).at(k)-data.at(j).at(k))*(data.at(i).at(k)-data.at(j).at(k));
            }
            for(int l=0;l<=len;l++){
                if(l*l==len) sum++;
            }
        }
    }
    cout<<sum<<endl;
}
