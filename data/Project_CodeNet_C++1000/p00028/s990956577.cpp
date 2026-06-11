#include <iostream>
using namespace std;
int main(){
    int a[100];
    for(int i=0;i<100;i++)
        a[i]=0;
    int x;
    while(cin >> x){
        a[x-1]+=1;
    }
    int max=0;
    for(int i=0;i<100;i++){
        if(max<a[i])
            max=a[i];
    }
    for(int i=0;i<100;i++){
        if(max==a[i])
            cout << i+1 << endl;
    }

}