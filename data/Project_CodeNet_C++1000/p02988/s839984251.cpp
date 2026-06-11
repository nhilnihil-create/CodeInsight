#include <iostream>
#include <vector>

using namespace std;

using std::vector;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int count = 0;
    for (int i = 0; i < n-2; i++)
    {
        if((numbers[i] < numbers[i+1] && numbers[i+1] < numbers[i+2]) || (numbers[i] > numbers[i+1] && numbers[i+1] > numbers[i+2]))
        {
            count++;
        }
    }

    cout << count << endl;


    return 0;
}