#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if((i+1)%2==1 && a%2==1){
            cnt++;
        }
    }
    cout << cnt << endl;
}

