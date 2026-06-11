#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string day[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string s;
    cin >> s;
    int ans=0;
    for(int i=0; i<7; i++)
    {
        if(day[i] == s)
        {
            ans = 7-i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
