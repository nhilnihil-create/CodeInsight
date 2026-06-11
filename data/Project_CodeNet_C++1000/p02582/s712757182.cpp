#include <bits/stdc++.h>
using namespace std;

int main()
{
    string three_days_weather;
    int days_rain = 0, max_rain = 0;

    cin >> three_days_weather;

    for(int i = 0; i < three_days_weather.size(); i++)
    {
        if(three_days_weather[i] == 'R')
        {
            days_rain++;
        }else{
            max_rain = max(max_rain, days_rain);
            days_rain = 0;
        }

    }
    max_rain = max(max_rain, days_rain);
    cout << max_rain << endl;
    return 0;
}