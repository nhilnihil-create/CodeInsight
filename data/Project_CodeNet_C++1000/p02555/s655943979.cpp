#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> v(2001);
    v[0] = 1;
    int x = 0;
    for(int i = 1;i < 2001;i++){
         if(i - 3 >= 0){
               x += v[i - 3];
               x %= 1'000'000'007;
         }
         v[i] = x;
    }
    cout << v[n] << endl;
}
