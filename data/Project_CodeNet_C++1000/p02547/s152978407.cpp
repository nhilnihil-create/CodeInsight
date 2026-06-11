#include <iostream>
 
using namespace std;
 
 
int main()
{
    int n,d1,d2,j=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>d1;
        cin>>d2;
        if (d1==d2){
            j++;
        }else if(d1!=d2 && j<3){
            j=0;
        }
    }
    if (j>2){
        cout<<"Yes";
    }else {
        cout<<"No";
    }
}
