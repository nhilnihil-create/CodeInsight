#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b;
    cin >> a >> b;
    long double temp_b = b / 2.0;
    long long places_in_b = (long long)ceil(temp_b);
    long long not_places_in_b = b - places_in_b;
    long double temp_a = a / 2.0;
    long long places_in_hr = (long long)ceil(temp_a);
    long long not_places_in_hr = a - places_in_hr;
    long long ans = (places_in_b * places_in_hr) + (not_places_in_b * not_places_in_hr);
    if(a == 1 || b == 1){
        cout<<1;
    }
    else
        cout<<ans<<endl;;
    //cout << places_in_b <<" "<<not_places_in_b<<endl; 
    //cout<<places_in_hr<<" "<<not_places_in_hr;
    
    return 0;
}