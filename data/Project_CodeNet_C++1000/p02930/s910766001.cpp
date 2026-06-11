#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;;k++){
                if(((i>>k)&1) != ((j>>k)&1)){
                    cout << k+1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}
