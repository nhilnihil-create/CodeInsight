#include<iostream>
using namespace std;
void call(int n) {
    int i = 1;
    for(i;i <= n;i++){
        if (i%3 == 0||i%10==3||i/10%10==3||i/100%10==3||i/1000%10==3) {
            cout << " " << i;
        }
   }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    call(n);
    return 0;
}
