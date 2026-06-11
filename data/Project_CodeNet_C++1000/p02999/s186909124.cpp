#include <iostream>

using namespace std;

    int
    main()
{
    int X{}, A{};

    cin >> X >> A;

    if(X < A) {
        cout << "0" << endl;
    }

    else if(X > A) {
        cout << "10" << endl;
    }

    else if(X == A) {
        cout << "10" << endl;
    }
}