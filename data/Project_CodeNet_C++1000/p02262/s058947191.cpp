#include<iostream>
#include<vector>

int insertSort( int data[], int dataNum, int gap ) {
    int cnt = 0;
    for( int i = gap; i < dataNum; i++ ) {
        int edgeVal = data[i];
        int cur = i;
        while( cur - gap >= 0 && data[cur - gap] > edgeVal ) {
            data[cur] = data[cur-gap];
            cur = cur - gap;
            cnt++;
        }
        data[cur] = edgeVal;
    }

    return cnt;
}

std::vector<int> getGaps( int dataNum ) {
    std::vector<int> ret;
    int i = 1;
    while( true ) {
        if( i > dataNum ) {
            break;
        }
        ret.push_back(i);
        i = 3*i + 1;
    }
    return ret;
}

int main() {
    int N;
    std::cin >> N;

    int data[N];
    for( int i = 0; i < N; i++ ) {
        std::cin >> data[i];
    }
    // int N = 10;
    // int data[] = {15,12,8,9,3,2,7,2,11,1};
    std::vector<int> gaps = getGaps(N);

    // Output:1列目
    std::cout << gaps.size() << std::endl;

    // Output:2列目
    for( int i = gaps.size() -1; i >= 0; i-- ) {
        if( i != gaps.size() -1 ) {
            std::cout << " ";
        }
        std::cout << gaps[i];
    }
    std::cout << std::endl;

    // shell sort
    int insCnt = 0;
    for( int i = gaps.size() -1; i >= 0; i-- ) {
        insCnt = insCnt + insertSort(data,N,gaps[i]);
    }
    // Output:3列目
    std::cout << insCnt;
    std::cout << std::endl;

    // Output:4列目
    for(int i = 0; i < sizeof(data)/sizeof(int);i++) {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;
}

// int main() {
//     int N;
//     std::cin >> N;

//     int data[N];
//     for( int i = 0; i < N; i++ ) {
//         std::cin >> data[i];
//     }
// }
