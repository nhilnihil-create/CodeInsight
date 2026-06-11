#include <bits/stdc++.h>

using namespace std;

// Define a struct that holds a string and also a in
struct each_set
{
    int total_val;
    string string_val;
};

int main()
{
    int N;
    cin >> N;
    string X;

    struct each_set * arr = new each_set[N];

    int total = 0;
    for(int i = 0; i < N ;i++)
    {
        int val;
        cin >> arr[i].string_val;
        cin >> val;
        total += val;
        arr[i].total_val = total;

    }

    cin >> X;


    for(int i = 0; i < N ;i++)
    {
        if(arr[i].string_val == X)
        {
            cout << arr[N - 1].total_val - arr[i].total_val << endl;

            break;
        }
    }



    return 0;
}