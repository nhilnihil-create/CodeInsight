#include <iostream>

int main()
{
    // given : A, B, N
    // 求めるもの: floor(Ax/B) - A*floor(x/B) のx <= Nについての最大値

    // floor(a/b) = (a - (a mod b))/b
    // floor(Ax/B) - A*floor(x/B)
    // = (Ax - (Ax mod B))/B - A*(x - (x mod B))/B
    // = (Ax - (Ax mod B) - Ax + A(x mod B))/B
    // = (- (Ax mod B) + A(x mod B))/B
    // = (A(x mod B) - (Ax mod B))/B >= 0
    // ここで x = CB + D (0 <= D <= B-1) とすると
    // = (A (CB+D mod B) - (A(CB+D) mod B))/B
    // = (A(D mod B) - (ACB+AD mod B))/B
    // = (A(D mod B) - (AD mod B))/B
    // C = 0 としてすると、0 <= x <= B-1
    // = (Ax - (Ax mod B))/B を最大にするようなx
    // <=> Ax - (Ax mod B) を最大にするようなx

    // x <= N かつ 0 <= x <= B-1
    long A, B, N;
    std::cin >> A >> B >> N;
    long x = std::min(N, B - 1);
    std::cout << (A * x - ((A * x) % B)) / B << std::endl;
}