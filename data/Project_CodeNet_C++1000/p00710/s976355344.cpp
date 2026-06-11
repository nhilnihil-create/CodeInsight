#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,r;
    while(cin>>n>>r,n){
        vector<int> hana,array;
        for(int i=n;i>=1;i--){
            hana.push_back(i);
        }
        for(int i=0;i<r;i++){
            int p,c;
            cin>>p>>c;
            for(int j=0;j<c;j++){
                array.push_back(hana[p-1+j]);
            }
            for(int j=p-2;j>=0;j--){
                hana[j+c]=hana[j];
            }
            hana=array;
            array.clear();
        }
        cout<<hana[0]<<endl;
    }
    return 0;
}