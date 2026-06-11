#include <iostream>
#include <string.h>

using namespace std;
int main() {
	char S[20];
	 cin >> S;

	 if(strncmp(S, "Sunny", 7) == 0)
	 {
		 printf("Cloudy");
	 }
	
   if(strncmp(S, "Cloudy", 7) == 0)
	 {
		 printf("Rainy");
	 }

		if(strncmp(S, "Rainy", 7) == 0)
	 {
		 printf("Sunny");
	 }

}