#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){

int i, n, a, b, c, value, cont = 0;
vector<int> vec;
cin >> n;

while(n--){
    cin >> value;
    vec.push_back(value);
}

for( i = 1; i < vec.size() - 1; ++i)
    if(vec[i] < vec[i+1] && vec[i] > vec[i-1] || vec[i] > vec[i+1] && vec[i] < vec[i-1])
        cont++;

cout << cont << endl;

    return 0;
}