#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calc(vector<string> title, vector<int> time, string end)
{
    int sum;
    
    string ti;
    int tm;
    
    sum = 0;
    
    ti = title.back();
    title.pop_back();
    
    while(ti != end) {
        tm = time.back();
        time.pop_back();
        
        sum += tm;
        
        ti = title.back();
        title.pop_back();
    }
    
    return sum;
}

int main(void)
{
    int n;
    
    vector<string> title;
    vector<int> time;

    string ti;
    int tm;
    string end;

    int sum;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ti >> tm;

        title.push_back(ti);
        time.push_back(tm);
    }
    
    cin >> end;

    sum = calc(title, time, end);

    cout << sum << endl;

    return 0;
}