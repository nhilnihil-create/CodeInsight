#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int s[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;cin>>k;
    k--;
    cout<<s[k]<<endl;
}