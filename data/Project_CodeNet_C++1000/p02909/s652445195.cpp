#include <bits/stdc++.h>

using namespace std;

int main(){
    string S,nextWeather;
    cin>>S;
    if(S=="Sunny")nextWeather="Cloudy";
    else if(S=="Cloudy")nextWeather="Rainy";
    else nextWeather="Sunny";
    cout<<nextWeather;
}