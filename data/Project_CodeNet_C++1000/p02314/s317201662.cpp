
#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    int totalValueOfShares;  //target sum
    int size; // number of coin types
    
    cin >> totalValueOfShares >> size;
    
    vector<int> numOfShares(size);
    vector<int> values(totalValueOfShares + 1);
    
    for(int i = 0; i < size; i ++){
        cin >> numOfShares[i];
    }
    
    values[0] = 0;
    
    int minValue = 0x7FFFFFFF;
    
   

            for (int i = 0; i < size; i ++)
            {
                if (numOfShares[i] < minValue)
                {
                    minValue = numOfShares[i];
                }
            }

            for (int i = 1; i <= totalValueOfShares; i++)
            {
                values[i] = 0x7FFFFFFF;
            }


            for (int i = minValue; i <= totalValueOfShares; i++)
            {
                for (int j = 0; j < size; j++)
                    if (numOfShares[j] <= i)
                    {
                        int sum = values[i - numOfShares[j]];
                        if (sum < 0x7FFFFFFF && sum + 1 < values[i])
                            values[i] = sum + 1;
                    }
            }
            if (values[totalValueOfShares] == 0x7FFFFFFF)
            {
                cout <<  0;
            }
            cout << values[totalValueOfShares] << "\r\n";    
    
    

    
}
