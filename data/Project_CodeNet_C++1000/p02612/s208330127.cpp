# include <iostream>

using namespace std;

int main()
{
    int price;

    cin >> price;

    while (price > 1000)
    {
        price -= 1000;
    }

    cout << 1000 - price;

    return 0;
}