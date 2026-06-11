#include <bits/stdc++.h>
using namespace std;

int main(){
 int n, k, MIN = 0 , x ,y;
 cin>>n>>k;
list<int>fruits;
for(int i = 0; i < n; i++){
    cin>>x;
    fruits.push_back(x);
 }
for(int j = 0; j < k; j++){
list<int>:: iterator y =min_element(fruits.begin(),fruits.end());
MIN += *y;
fruits.erase(y);
}
cout<<MIN<<endl;
    return 0;
}

