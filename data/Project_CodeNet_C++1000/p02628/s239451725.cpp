#include <iostream>
#include <string>

using namespace std;

int main()
{
    // input first line
    int N; int K;
    cin >> N; cin >> K;
    cout << endl;
    int price; int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> price;
        arr[i] = price;
        cout << " ";
    }
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int y = i+1; y < N; y++)
        {
            if (arr[i] > arr[y])
            {
                temp = arr[i];
                arr[i] = arr[y];
                arr[y] = temp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;





    return 0;
}
